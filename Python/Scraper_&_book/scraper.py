import urllib2
from bs4 import BeautifulSoup
import requests

const_url = 'https://www.italian-verbs.com/italian-verbs/conjugation.php'
conjugations = dict()


""" 
def conj(url, prev, word):
    dom = BeautifulSoup(urllib2.urlopen(url), 'html.parser')
    table = dom.find_all(attrs={'class': 'col span_1_of_2'})
    for row in table.find_all('tr'):
        if row.get_text() == 'IMPERFETTO':
            break
        conjugations[word].append(row.get_text())
    print conjugations
 """


def check(word):
    with open('verb.txt', 'r') as f:
        if word in f.read():
            return true
        return false


def read_book():
    with open('book.txt', 'r') as f:
        for line in f:
            for word in line.split():
                if check(word):
                    with open('ans.txt', 'r') as ans:
                        ans.write(word)
                        ans.write('\n')


def scrape(url, prev):
    f = open("verbs.txt", "a+")
    dom = BeautifulSoup(urllib2.urlopen(url), 'html.parser')
    divs = dom.find_all(attrs={'class': 'col span_1_of_2'})
    for div in divs:
        for a in div.find_all('a'):
            word = a.get_text().strip()
            if word[0] != prev:
                prev = word[0]
                f.write('\n')
                break
            if prev == 'z' and word[0] == 'a':
                print finished
                exit()
            f.write(word + ' ')
    pag = dom.find_all(id='pag')
    for p in pag:
        if p.get_text() == 'Pagina successiva':
            new_url = url + p.find('a')['href']
            scrape(new_url, prev)
    f.close()


scrape(const_url, '\0')
