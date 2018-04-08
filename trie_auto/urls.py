# -*- coding: utf-8 -*-
from django.conf.urls import url
from trie_auto.views import auto_trie, complete

urlpatterns = [
    url(r'^auto_trie/$', auto_trie, name='auto_trie'), 
    url(r'^complete/$', complete, name='complete')
]
