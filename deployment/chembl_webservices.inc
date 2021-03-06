WSGIApplicationGroup %{GLOBAL}
WSGIPassAuthorization On
WSGIDaemonProcess webservices user=chembl group=chembl threads=4 \
   python-path=/home/chembl/rdkit:/home/chembl/indigo-python-1.1.11-linux:/home/chembl/chembl_webservices/deployment/:/home/chembl/.virtualenvs/chembl_webservices/lib/python2.7/site-packages/:/home/chembl/.virtualenvs/chembl_beaker/lib/python2.7/site-packages/:/home/chembl/chembl_beaker/conf.d/
WSGIScriptAlias /chemblws /home/chembl/chembl_webservices/deployment/deployment/wsgi.py/chemblws
WSGIScriptAlias /utils /home/chembl/chembl_beaker/conf.d/beaker.py

SetEnv LD_LIBRARY_PATH /home/chembl/rdkit/lib
SetEnv LANG en_US.UTF-8
SetEnv LC_ALL en_US.UTF-8

Alias /static/ /home/chembl/chembl_webservices/deployment/deployment/static/
<Location "/static/">
  Options -Indexes
</Location>

<Directory /home/chembl/chembl_webservices/deployment/deployment/>
  WSGIProcessGroup webservices
  Order allow,deny
  Allow from all
</Directory>
