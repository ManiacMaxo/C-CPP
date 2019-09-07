import requests
import time
import urlparse
import string
from bs4 import BeautifulSoup

m_url = 'https://www.italian-verbs.com/italian-verbs/conjugation.php'  # master url


def get_verb_conj(url, prev_url):
    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print 'failed with status code ' + response.status_code + '\n'
        time.sleep(2)  # wait 2 seconds
        response = requests.get(url)
    html = response.text
    clean = BeautifulSoup(html, 'html.parser')
    table = clean.find_all(attrs={'class': 'col span_1_of_2'})

    conjunctions = []
    for row in table:
        for a in row.find_all('td'):
            verb = a.get_text().strip()
            if verb[0].isupper():  # check first character
                continue
            n_verb = verb.split()
            conjunctions.append(n_verb[-1])  # takes only the last word
    return conjunctions


def scrape(url, prev_c):
    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print 'failed with status code ' + response.status_code + '\n'
        time.sleep(2)  # wait 2 seconds
        response = requests.get(url)
    html = response.text
    clean = BeautifulSoup(html, 'html.parser')
    verbs = clean.find_all(attrs={'class': 'col span_1_of_2'})

    for verb in verbs:
        if prev_c == 'z' and verb[0] == 'a':
            print 'fin'
            break
        for a in verb.find_all('a'):
            verb = a.get_text().strip()
            temp = '?lemma=' + verb.upper() + '100'
            v_url = urlparse.urljoin(m_url, temp)
            with open('verb.txt', 'a') as f:
                f.write(get_verb_conj(v_url, url))
                print verb


scrape(m_url, 'a')
