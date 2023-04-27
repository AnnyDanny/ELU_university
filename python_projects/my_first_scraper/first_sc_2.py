import requests
from bs4 import BeautifulSoup
import csv


def request_github_trending(url):
    response = requests.get(url)
    html_content = response.content
    return html_content


def extract(page):
    soup = BeautifulSoup(page, 'html.parser')
    return soup


def transform(html_repos):
    result = []
    list_name_and_repos = []
    list_of_stars = []

    soup = extract(request_github_trending(html_repos))

    for div in soup.find_all("div", class_="BtnGroup d-flex"):
        link = div.find("a")["href"]
        link = link.split("%2F")
        name = link[1]
        repos_name = link[2]

        list_name_and_repos.append({"developer_name": name, "project": repos_name})

    for span in soup.find_all("span", class_="d-inline-block float-sm-right"):
        stars = span.text.strip()
        number_of_stars = stars.split(" ")[0]

        list_of_stars.append({"nbr_stars": number_of_stars})

    for i in range(len(list_name_and_repos)):
        result.append(list_name_and_repos[i])
        result[i].update(list_of_stars[i])

    return result


# Defnition of format function should be like this: def format("repositories_data")
# Not: def format(repository)
# According to the Subject this function should: taking a repository array of hash
# and transforming it and returning it into a CSV string. Each column will be separated by , and each line by \n

def format(repository):
    # csv header
    fieldnames = ["developer_name", "project", "nbr_stars"]

    # csv data
    # If you change "repository" to "repositories_data" you have to change "repository" to "repositories_data" at the next line as well:
    rows = repository

    # Below functionality just open the file, which located locally in your repo. Gandalf doesn't have this file, that's why you get erros.
    # According to Subject you have: transforming array of hash and returning it into a CSV string.
    # You shouldn't open any files.
    with open('trending_git.csv', 'w', encoding='UTF8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


# Below code: calling all function one by one, how it is in Subject.
# You can use this code to refactor your code localy, but you need to comment it when tou run Gandalf.

url = "https://github.com/trending"
page = request_github_trending(url)
# print(page)
html_repos = extract(page)
repositories_data = transform(html_repos)
#print(repositories_data)
csv_string = format(repositories_data)

#print(csv_string)