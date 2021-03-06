# Copyright 2008 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from django.conf.urls.defaults import *

from . import views

urlpatterns = patterns('',

    url(r'^get_scores', views.get_scores, name='get_scores'),
    url(r'^get_time', views.get_time, name='get_time'),
    url(r'^get_word', views.get_word, name="get_word"),
    url(r'^post_score/(?P<user_name>.+)', views.post_score, name="post_score"),
    
    url(r'^choosewords', views.choosewords, name="choosewords"),    # admin view to choose upcoming daily words.

)

