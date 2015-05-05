/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


var drupalArticleApp = angular.module('drupalArticleApp', []);

drupalArticleApp.controller('ArticleListCtrl', function ($scope) {
  $scope.articles = [
    {'title': 'Nexus S',
     'body': 'Fast just got faster with Nexus S.'},
    {'title': 'Motorola XOOM™ with Wi-Fi',
     'body': 'The Next, Next Generation tablet.'},
    {'title': 'MOTOROLA XOOM™',
     'body': 'The Next, Next Generation tablet.'}
  ];
});