import { NgModule } from '@angular/core';
import { IonicPageModule } from 'ionic-angular';
import { VisitePage } from './visite';

@NgModule({
  declarations: [
    VisitePage,
  ],
  imports: [
    IonicPageModule.forChild(VisitePage),
  ],
  exports: [
    VisitePage
  ]
})
export class VisitePageModule {}
