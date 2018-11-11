#!/usr/bin/env node

const net = require('net')


function onLine(line, socket) {
	socket.lineCnt++
	socket.request = {
		cmd: '',
		uri: '',
		proto: '',
		ver: ''
	}
	if (line == '') {
		console.log('!!! end of message. replying... \n')
		socket.write('HTTP/1.1 200 OK\n\nHello world')
		socket.end()
		return
	}
	if (socket.lineCnt === 1) {
		var i=0
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
		console.log(socket.request)
	} else {
		console.log('Header> %s', line)
	}
}

var srv = new net.Server()
	.on('connection', function(socket) {
		socket.lineCnt = 0
		var line = ''
		var lastIsCrLf = false
		console.log('connected from %s:%s\n', socket.remoteAddress, socket.remotePort)
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
	})
	.on('error', function(err){
		console.log(err)
	})
	.on('listening', function() {
		console.log('listening at %s:%d', srv.address().address, srv.address().port)
	})
	.listen({
		host: 'localhost',
		port: 8080
	})