import requests
from bs4 import BeautifulSoup
import sys

article_url = sys.argv[1]
r = requests.get(article_url)
soup = BeautifulSoup(r.text, 'html.parser')

print("Title: ", soup.title.string)
print("Headline: ", soup.find(attrs={"data-testid": "headline"}).string)
print("Sub Headline: ", soup.find(
    attrs={"data-testid": "subheadline"}).string)
print("Author: ", soup.find(rel='author').string)
print("Date: ", soup.find(
    attrs={"data-testid": "display-date"}).string)

paragraphs = soup.find_all(attrs={"data-qa": "article-body"})
for paragraph in paragraphs:
    if paragraph.find(attrs={"data-testid": "drop-cap-letter"}):
        print("\n", paragraph.find(
            attrs={"data-testid": "drop-cap-letter"}).text)
    if paragraph.find(attrs={"data-apitype": "list"}):
        print("\n")
        ul = paragraph.find(attrs={"data-apitype": "list"})
        li_list = ul.find_all('li')
        for li in li_list:
            print("# ", li.text)
