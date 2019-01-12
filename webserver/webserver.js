#!/usr/bin/env node

const http = require('./http.js')

new http.Server(8080)
	.on('request', function (req, res) {
		res.write('Hello World !!!')
		res.end()
	})
	.run()