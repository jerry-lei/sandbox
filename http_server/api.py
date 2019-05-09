from flask import Flask, make_response, Response
from werkzeug.serving import WSGIRequestHandler
from flask import jsonify

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def do_root():
    resp = make_response("{'my':'response'}")
    return resp

if __name__ == '__main__':
    WSGIRequestHandler.protocol_version = 'HTTP/1.1'
    app.run()
