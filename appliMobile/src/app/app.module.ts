import { BrowserModule } from '@angular/platform-browser';
import { NgModule, ErrorHandler } from '@angular/core';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { MyApp } from './app.component';

import { StatusBar } from '@ionic-native/status-bar';
import { SplashScreen } from '@ionic-native/splash-screen';

import { ControlPage } from '../pages/control/control';
import { VisitePage } from '../pages/visite/visite';
import { ControleurVisite } from '../providers/controleur-visite/controleur-visite';


@NgModule({
  declarations: [
    MyApp,
    VisitePage,
    ControlPage
  ],
  imports: [
    BrowserModule,
    IonicModule.forRoot(MyApp),
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    VisitePage,
    ControlPage
  ],
  providers: [
    StatusBar,
    SplashScreen,
    {provide: ErrorHandler, useClass: IonicErrorHandler},
    ControleurVisite
  ]
})
export class AppModule {}
