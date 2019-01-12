const net = require('net')
const util = require('util')
const EventEmitter = require('events')
const StatusCodes = require('./statusCodes.js')

class BaseHTTPMessage extends EventEmitter {
	constructor(socket) {
		super()
		this.socket = socket
		this.protocol = ''
		this.version = ''
		this.headers = {}
	}

	setHeader(hdr, val) {
		this.headers[hdr] = val
	}

	getHeader(hdr) {
		return this.headers[hdr]
	}
}

class Request extends BaseHTTPMessage {
	constructor(socket) {
		super(socket)
		this.method = ''
		this.uri = ''
	}
}

class Response extends BaseHTTPMessage {
	constructor(socket) {
		super(socket)
		this.responseCode = '200'
		this.protocol = 'HTTP'
		this.version = '1.1'
		this.headersSent = false
	}

	setResponseCode(code) {
		this.responseCode = '' + code
	}

	getResponseCode() {
		return this.responseCode
	}

	sendHeaders() {
		var self = this
		this.socket.write(this.protocol + '/' + this.version + ' ' + this.responseCode + ' ' + StatusCodes[this.responseCode] + '\r\n')
		Object.keys(this.headers).forEach(function (header) {
			self.socket.write(header + ': ' + self.headers[header] + '\r\n')
		})
		this.socket.write('\r\n')
		this.headersSent = true
	}

	write(data) {
		if (!this.headersSent) {
			this.sendHeaders()
		}
		this.socket.write(data)
	}

	end(data) {
		if (!this.headersSent) {
			this.sendHeaders()
		}
		this.socket.end(data)
	}
}

class Server extends EventEmitter {

	constructor(port) {
		super()
		this.tcpServer = net.Server()
		this.port = port
		this.tcpServer.on('connection', this.onConnection.bind(this))
		this.tcpServer.on('error', this.onError.bind(this))
		this.tcpServer.on('listening', this.onListening.bind(this))
	}

	onListening() {
		console.log('listening at %s:%d', this.tcpServer.address().address, this.tcpServer.address().port)
	}

	onError(err) {
		console.log(err)
	}

	onConnection(socket) {
		var self = this
		var line = ''
		var lastIsCrLf = false
		console.log('\nconnected from %s:%s', socket.remoteAddress, socket.remotePort)
		socket.on('data', function (data) {
			data = '' + data
			for (var i = 0; i <= data.length; i++) {
				if (data[i] === '\r' || data[i] === '\n') {
					if (!lastIsCrLf) {
						self.onLine(line, socket)
						line = ''
						lastIsCrLf = true
					} else {
						lastIsCrLf = false
					}
				} else {
					lastIsCrLf = false
					line += data[i]
				}

			}
		})
	}

	onLine(line, socket) {
		socket.lineCnt++
		var i = 0
		if (line == '') { // empty line
			this.emit('request', socket.request, new Response(socket))
		} else if (socket.request === undefined) { // first line
			socket.request = new Request(socket)
			const cmdDelim = {
				method: ' ',
				uri: ' ',
				protocol: '/',
				version: ' ',
			}
			Object.keys(cmdDelim).forEach(function (key) {
				while (line[i] != cmdDelim[key] && i < line.length) {
					socket.request[key] += line[i++]
				}
				i++
			});
		} else { // header: value 
			var key = '',
				value = '',
				metColon = false
			while (line[i] != ' ' && line[i] != '\t' && line[i] != ':') {
				key += line[i]
				i++
			}
			while (line[i] == ' ' || line[i] == '\t' || line[i] == ':') {
				metColon = metColon || line[i] == ':'
				i++
			}
			if (!metColon)
				throw 'invalid header key'
			for (; i < line.length; i++)
				value += line[i]
			socket.request.setHeader(key, value)
		}
	}

	run() {
		this.tcpServer.listen({
			host: 'localhost',
			port: this.port,
		})
	}

}

module.exports = {
	StatusCodes,
	Server,
	Request,
	Response,
}