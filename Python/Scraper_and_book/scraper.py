import requests
import time
import urlparse
import string
import re
from bs4 import BeautifulSoup


m_url = 'https://www.italian-verbs.com/italian-verbs/conjugation.php'  # master url


def get_verb_conj(url, prev_url):
    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print('failed with status code ', response.status_code, '\n')
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
            verb = a.get_text().encode('utf-8').strip()
            temp = verb.split()
            verb = temp[-1]
            if verb[0].isupper() or re.search(r'\d', verb) == 0:  # check validity
                continue
            conjunctions.append(verb)  # takes only the last word
    return conjunctions


def scrape(url, prev_w):

    if 'zoomare' in url:  # exit condition, didn't work
        print('fin')
        exit()

    response = requests.get(url)
    while(response.status_code != 200):  # repeat until correct status code
        print('failed with status code ', response.status_code, '\n')
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
                print(verb)
                with open('verbs.txt', 'a') as f:
                    for word in conjugated_verbs:
                        f.write('%s ' % word)
                    print >> f
            else:
                print('No conjugations for ', verb)

    pag = clean.find_all(id='pag')  # find next page
    for p in pag:
        if p.get_text() == 'Pagina successiva':
            temp = p.find('a')['href']
    new_url = urlparse.urljoin(url, temp)
    time.sleep(5)
    scrape(new_url, prev_w)


#scrape(m_url, 'a', '')
