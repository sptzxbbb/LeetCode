#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import requests
from bs4 import BeautifulSoup

# params: query parameters in url, represented as a Dict
# headers: request headers, represented as a Dict
# data: form-encoded data, represented as a Dict
headers = {'user-agent': 'my-app/0.0.1'}

payload = {'key1': 'value1', 'key2': 'value2'}
r = requests.post('https://httpbin.org/post', data=payload)
print(r.text)
