import requests
import time
import urlparse
import string
import re
from bs4 import BeautifulSoup


def check(word):
    with open('verbs.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            if re.search(r'some_pattern', line):
                words = line.split()
                with open('ans.txt', 'a') as ans:
                    for i in range(6):
                        ans.write(words[i] + ' ')
                    print >> ans


def read_book():
    with open('book.txt', 'r') as b:
        for line in b:
            for word in line.split():
                check(word)


m_url = 'https://www.italian-verbs.com/italian-verbs/conjugation.php'  # master url


def get_verb_conj(url, prev_url):
    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print 'failed with status code ' + response.status_code + '\n'
        if response.status_code == 404:
            return  # bail out if page not found
        time.sleep(2)  # wait 2 seconds
        response = requests.get(url)
    html = response.text
    clean = BeautifulSoup(html, 'html.parser')
    table = clean.find_all(attrs={'class': 'col span_1_of_2'})

    conjunctions = []
    for row in table:
        for a in row.find_all('td'):
            verb = a.get_text().strip()
            if verb[0].isupper() or verb.isalpha() == 0:  # check first character
                continue
            n_verb = verb.split()
            conjunctions.append(n_verb[-1])  # takes only the last word
    return conjunctions


def scrape(url, prev_c, prev_w):

    if 'zoomare' in url:  # exit condition
        print 'fin'
        read_book()
        exit()

    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print 'failed with status code ' + response.status_code + '\n'
        time.sleep(2)  # wait 2 seconds
        response = requests.get(url)
    html = response.text
    clean = BeautifulSoup(html, 'html.parser')
    verbs = clean.find_all(attrs={'class': 'col span_1_of_2'})

    first = True
    for verb in verbs:
        for a in verb.find_all('a'):  # find all a tags on page
            if first:  # skip first word in table
                first = False
                continue
            verb = a.get_text().strip()
            if verb == prev_w:
                continue
            else:
                prev_w = verb
            temp = '?lemma=' + verb.upper() + '100'
            v_url = urlparse.urljoin(m_url, temp)  # create sub link
            # error hangling if no conjugate verbs
            conjugated_verbs = get_verb_conj(v_url, url)
            if conjugated_verbs:
                print verb
                with open('verb.txt', 'a') as f:
                    for word in conjugated_verbs:
                        f.write('%s ' % word)
                    print >> f
            else:
                print 'No conjugations for ', verb

    pag = clean.find(id='pag', attrs={})
    for p in pag:
        if p.get_text() == 'Pagina successiva':
            new_url = urlparse.urljoin(url, p.find('a')['href'])
            print new_url
    scrape(new_url, prev_c, prev_w)


scrape(m_url, 'a', '')
