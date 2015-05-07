/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


var drupalArticleApp = angular.module('drupalArticleApp', []);

drupalArticleApp.controller('ArticleListCtrl', function ($scope, $http) {

   /*$scope.articles = [
    {'title': 'Nexus S',
     'body': 'Fast just got faster with Nexus S.',
 'created' : 1},
    {'title': 'Motorola XOOM™ with Wi-Fi',
     'body': 'The Next, Next Generation tablet.',
 'created' : 2},
    {'title': 'MOTOROLA XOOM™',
     'body': 'The Next, Next Generation tablet.',
 'created' : 3}
  ];*/
  
  $scope.articles = [];
 $http.get('node-data/article')
       .success(function(res){
          $scope.articles = res;
        });
        console.log($scope.articles);
      $scope.orderProp = 'created';   
});
