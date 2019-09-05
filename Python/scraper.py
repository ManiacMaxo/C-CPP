import urllib2
from bs4 import BeautifulSoup


def index(url):
    html = urllib2.urlopen(url)
    dom = BeautifulSoup(html, 'html.parser')
    divs = dom.find_all(attrs={'class': 'col span_1_of_2'})
    for div in divs:
        for a in div.find_all('a'):
            print a.get_text().strip(), a['href']
    print
    pag = dom.find_all(id='pag')
    for p in pag:
        if p.get_text() == 'Pagina successiva':
            print p.find('a')['href']


index('https://www.italian-verbs.com/italian-verbs/conjugation.php')
