import csv

def movie_filter(genre):

    filename = "imdb-movie-data.csv"
    result = []

    with open(filename) as csvfile:
        csv_content = csv.DictReader(csvfile)

        for movie in csv_content:
            genres = movie["Genre"].split(",")
            if genre in genres:
                result.append(movie)

    return result
