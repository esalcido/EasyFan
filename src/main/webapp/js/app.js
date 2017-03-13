

var app = angular.module('myApp',['ui.bootstrap']);

app.controller('myCtrl', function($scope,$http){


//get state
$scope.state;

$http.get("/rest/toggle/state")
    .then(function(response){
        $scope.state = response.data.state;

    });


$scope.bigData = {};

$scope.bigData.fan = localStorage.getItem("fan")? JSON.parse(localStorage.getItem("fan")) : false;
$scope.bigData.another = false;

//use $watch to listen to any change from state
$scope.$watch("bigData.fan", function(newVal,oldVal){
    if(oldVal !== newVal){

        localStorage.setItem("fan",newVal);

       $http.get("/rest/toggle/"+newVal+"")
                          .then(function(response){
                              $scope.myWelcome = response.data.state;

                          });
    }

});


});

