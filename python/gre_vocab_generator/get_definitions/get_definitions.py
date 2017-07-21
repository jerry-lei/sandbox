import requests
import json
import time

ListOfWords = []
DictionaryOfWords = {}

fileWords = open("FullVocabList.txt","r")
readFileWords = fileWords.read()
ListOfWords = readFileWords.splitlines()


#remember to delete this
request = {
  "Accept": "application/json",
  "app_id": "300a8e23",
  "app_key": "afebf71535e28e852996f7e5a605c255"
}

for word in ListOfWords:
    query = "https://od-api.oxforddictionaries.com:443/api/v1/entries/en/" + word
    response = requests.get(query, headers=request)
    time.sleep(1)
    try:
        responseJson = response.json()
        definitionTypes = responseJson["results"][0]["lexicalEntries"]
        definitionString = ''
        for lexicalEntry in definitionTypes:
            category = lexicalEntry["lexicalCategory"]
            definition = lexicalEntry["entries"][0]["senses"][0]["definitions"][0]
            definitionString += '\t(' + category + '): ' + definition + '\n'
        DictionaryOfWords[word] = definitionString
    except:
        print "Definition Missing: " + word


for key in DictionaryOfWords.keys():
    print key + "- "
    print DictionaryOfWords[key]
