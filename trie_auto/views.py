# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from django.shortcuts import render
from django.shortcuts import render
from django.template import RequestContext
from django.http import HttpResponseRedirect
from django.core.urlresolvers import reverse
from random import *
import os, shlex

import subprocess

def auto_trie(request):
	gift="mmm"
	return render(request,'list.html',{'gift': gift })

def complete(request):
	vat=randint(1,100)
	quer = request.GET.get('search_query')
	if(quer==""):
		return render(request,'trie_box.html',{'vat': "type"})
	sol_dir_path=os.path.join(os.path.dirname(os.path.dirname(__file__)))
	# # print sol_dir_path
	# # print quer
	compile_proc = subprocess.check_output('./trie '+quer,
                                    cwd=sol_dir_path, shell=True,)
	compile_proc = list(compile_proc.split('\n'))


	return render(request,'trie_box.html',{'vat': compile_proc })


