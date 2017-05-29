import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
import { Observable } from 'rxjs/Rx';
import 'rxjs/add/operator/map';

import {ModelVisite } from '../../models/modelVisite';
/*
  Generated class for the ControleurVisiteProvider provider.

  See https://angular.io/docs/ts/latest/guide/dependency-injection.html
  for more info on providers and Angular 2 DI.
*/
@Injectable()
export class ControleurVisite {
 jsonApiUrl='http://127.0.0.1/~akhasanov/json-php/chargeVille.php';
  constructor(public http: Http) { }
    load(): Observable<ModelVisite[]>{
	
	return this.http.get('${this.jsonApiUrl}?idControleur=2').map(res => <ModelVisite[]>res.json());

	}

}
