import requests
import urlparse
import time
from bs4 import BeautifulSoup

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
            return 1
        return 0


def read_book():
    with open('book.txt', 'r') as f:
        for line in f:
            for word in line.split():
                if check(word):
                    with open('ans.txt', 'r') as ans:
                        ans.write(word)
                        ans.write('\n')


def scrape(url, prev):
    f = open('verbs.txt', 'a')
    response = requests.get(url)
    html = response.text
    while(html.status_code != 200):  # repeat until correct status code
        print 'failed with status code ' + html.status_code + '\n'
        time.sleep(2)  # wait 2 seconds
        html = requests.get(url)
    dom = BeautifulSoup(html, 'html.parser')  # parse html

    divs = dom.find_all(attrs={'class': 'col span_1_of_2'})  # find verbs

    for div in divs:
        for a in div.find_all('a'):
            word = a.get_text().strip()
            if word[0] != prev:
                prev = word[0]
                f.write('\n')
                continue
            if prev == 'z' and word[0] == 'a':
                print 'finished'
                exit()
            f.write(word + ' ')

    pag = dom.find(id='pag', name='Pagina successiva')[
        'href']  # open next page
    new_url = urlparse.urljoin(url, pag)
    #scrape(new_url, prev)
    f.close()


scrape(const_url, 'a')
