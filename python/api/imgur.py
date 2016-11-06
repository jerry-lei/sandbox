import json
import requests
import base64

#get client-id (Users/Jerry/Documents/api_keys/api_imgur.txt on macbook air)
fd = open("/Users/Jerry/Documents/api_keys/api_imgur.txt")
keys = fd.read().split('\n')
fd.close()

CLIENT_ID = keys[0]
CLIENT_SECRET = keys[1]

url_image = "https://api.imgur.com/3/image"
url_album = "https://api.imgur.com/3/album"

def upload_local(fpath):
    r = requests.post(url_image, data = {'image': open(fpath,'rb').read(),
                                        'type': 'file'},
                                        headers = {'Authorization': 'Client-ID ' + CLIENT_ID})
    data = r.json()
    image_id = data.get('data').get('id')
    return image_id

#print 'https://imgur.com/' + upload_local("/Users/Jerry/Documents/Wallpapers/SS.jpg")
