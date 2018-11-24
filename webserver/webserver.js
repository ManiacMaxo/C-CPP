#!/usr/bin/env node

const net = require('net')

function onLine(line, socket) {
	socket.lineCnt++
	var i=0
	if (line == '') {
		console.log('end of message. replying...')
		console.log(socket.request)
		socket.write('HTTP/1.1 200 OK\n\nHello world')
		socket.end()
		return
	} else if (socket.request === undefined) {
		socket.request = {
			cmd: '',
			uri: '',
			proto: '',
			ver: '',
			headers: {},
		}
		const cmdDelim = {
			cmd: ' ',
			uri: ' ',
			proto: '/',
			ver: ' ',
		}
		Object.keys(cmdDelim).forEach(function(key) {
			while(line[i] != cmdDelim[key] && i<line.length) {
				socket.request[key] += line[i++]
			}
			i++
		});
	} else {
		var key = '', value = '', metColon = false
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
		socket.request.headers[key] = value
	}
}

function onConnection(socket) {
	var line = ''
	var lastIsCrLf = false
	console.log('\nconnected from %s:%s', socket.remoteAddress, socket.remotePort)
	socket.on('data', function(data) {
		data = '' + data
		for (var i=0; i<= data.length; i++) {
			if (data[i] === '\r' || data[i] === '\n') {
				if (!lastIsCrLf) {
					onLine(line, socket)
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

function onError(err) {
	console.log(err)
}

function onListening() {
	console.log('listening at %s:%d', srv.address().address, srv.address().port)
}

var srv = new net.Server()
srv.on('connection', onConnection)
srv.on('error', onError)
srv.on('listening', onListening)

srv.listen({
	host: 'localhost',
	port: 8080
})