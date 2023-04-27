from flask import Flask
from flask import request
import csv
import json


app = Flask(__name__)

lines = ""

with open('imdb-movie-data.csv') as f:
    lines = f.readlines()

keys = lines[0].strip().split(",")

def find_movie_by_genre(name):
    result = []
    for i in range(1, len(lines)):
        split_str = csv.reader([lines[i].strip()], delimiter=',')
        row = next(split_str)
        if name.lower() in row[2].lower():
            res_dict = {}
            for j in range(len(keys)):
                res_dict[keys[j]] = row[j].replace("\t",";")
                if keys[j] == "Rating" or keys[j] == "Revenue (Millions)" or keys[j] == "Metascore":
                    if row[j] != "":
                        res_dict[keys[j]] = float(row[j])
                elif row[j].isnumeric():
                    res_dict[keys[j]] = int(row[j])
            result.append(res_dict)
    return json.dumps(result)



@app.route('/')
def genre():
    name = request.args.get('genre')
    if name is not None:
        return find_movie_by_genre(name)
    else:
        return "Genre is missing", 400


@app.route('/action')
def action():
   return find_movie_by_genre("action")


@app.route('/mystery')
def mystery():
   return find_movie_by_genre("mystery")


@app.route('/adventure')
def adventure():
   return find_movie_by_genre("adventure")



@app.route('/comedy')
def comedy():
   return find_movie_by_genre("comedy")


@app.route('/drama')
def drama():
   return find_movie_by_genre("drama")


@app.route('/romance')
def romance():
   return find_movie_by_genre("romance")



if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080, debug=True)