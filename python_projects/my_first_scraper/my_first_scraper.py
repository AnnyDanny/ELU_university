import requests
from bs4 import BeautifulSoup
import re


def request_github_trending(url):
    response = requests.get(url)

    return response


def extract(page):
    soup = BeautifulSoup(page.text, "html.parser")

    # Get articles, class: "Box-row" for all Github users and save them to set "articles"
    articles = soup.find_all(
        'article', attrs={'class':
                              'Box-row'})

    return articles


def transform(html_repos):
    # Get name and repos of all user and save them to array "array_of_names_and_repo"
    array_of_names_and_repo = []
    mydivs = []
    for article in html_repos:
        array_of_names_and_repo.append(article.find('h2').find('a')['href'])
        mydivs.append(article.find("div", {"class": "f6 color-fg-muted mt-2"}))

    # Split array_of_names_and_repo and save names to array "name" and repositories to array "repository"
    array_of_names = []
    array_of_repositories = []
    for i in range(0, len(array_of_names_and_repo)):
        name_and_repo = array_of_names_and_repo[i]
        array_of_names.append(name_and_repo.split("/")[1])
        array_of_repositories.append(name_and_repo.split("/")[2])

    # Get all "a" tags and save them to array "aray_of_atags"
    aray_of_atags = []
    for mydiv in mydivs:
        aray_of_atags.append(mydiv.find('a'))

    # Get all starts from array of tags "a" and save them to erray "all_stars
    all_stars = []
    for star in aray_of_atags:
        star = re.sub('[\n" "]', '', star.text)
        all_stars.append(star)

    # Create array of dicts and add names, repos and nbr_stars
    array_of_dicts = []
    for i in range(0, len(array_of_names)):
        my_dict = {
            "developer": array_of_names[i],
            "repository_name": array_of_repositories[i],
            "nbr_stars": all_stars[i]
        }
        array_of_dicts.append(my_dict)

    return array_of_dicts


def format(repositories_data):
    # Transorm array_of_dicts into csv string
    array_of_strings = ["Developer, Repository name, Number of stars"]
    for i in range(0, len(repositories_data)):
        fstring = f'{repositories_data[i]["developer"]}, {repositories_data[i]["repository_name"]}, {repositories_data[i]["nbr_stars"]}'
        array_of_strings.append(fstring)
    csv_string = '\n'.join(array_of_strings)

    return csv_string


url = "https://github.com/trending"

page = request_github_trending(url)
#print(page.text)
html_repos = extract(page)
repositories_data = transform(html_repos)
print(repositories_data)
#csv_string = format(repositories_data)

#print(csv_string)
