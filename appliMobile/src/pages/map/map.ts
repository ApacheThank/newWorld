import { Component,ViewChild, ElementRef } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';

import {ControleurVisite } from '../../providers/controleur-visite/controleur-visite';
//import { VisitePage } from '../visite/visite';


declare var google;

/**
 * Generated class for the MapPage page.
 *
 * See http://ionicframework.com/docs/components/#navigation for more info
 * on Ionic pages and navigation.
 */
@IonicPage()
@Component({
  selector: 'page-map',
  templateUrl: 'map.html',
})
export class MapPage {

  @ViewChild('map') mapElement: ElementRef;
  map: any;
  start = 'gap, france';
  end = 'gap, france';
  directionsService = new google.maps.DirectionsService;
  directionsDisplay = new google.maps.DirectionsRenderer;



 constructor(public navCtrl: NavController, public navParams: NavParams, private controleurVisite : ControleurVisite) {  }

ionViewDidLoad(){
    // console.log('ionViewDidLoad VisitePage');
    this.initMap();
    //ici j'ajoute le passage par sigoyer
    this.waypts[0]= {location:'sigoyer france', stopover:true};
    //et manteyer
    this.waypts[1]= {location:'manteyer france', stopover:true};

	}

initMap() {
    this.map = new google.maps.Map(this.mapElement.nativeElement, {
      zoom: 25,
      center: {lat: 44.556, lng: 6.079}
    });

this.map.setTilt(45);
    this.directionsDisplay.setMap(this.map);
  }
//tableau des points de passage
  waypts = [];
  

  calculateAndDisplayRoute() {
    this.directionsService.route({
      origin: this.start,
      destination: this.end,
      waypoints: this.waypts,
      optimizeWaypoints: true,
      travelMode: 'DRIVING',
      drivingOptions: {departureTime: new Date(Date.now() + 1000*60*60),trafficModel: 'optimistic'}
    }, (response, status) => {
      if (status === 'OK') {
        this.directionsDisplay.setDirections(response);
      } else {
        window.alert('Directions request failed due to ' + status);
      }
  });
}
}
