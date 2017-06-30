

var app = angular.module('myApp',['ui.bootstrap']);

app.controller('myCtrl', function($scope,$http){
    //get state
    $scope.state;

    $http.get("/rest/toggle/state")
        .then(function(response){
            $scope.state = response.data.state;

        });

    $scope.bigData = {};

    //check local storage for the state of the fan.  If it is on
    $scope.bigData.light = localStorage.getItem("light")? JSON.parse(localStorage.getItem("light")) : false;
    $scope.bigData.air = false;

    //use $watch to listen to any change from state
    $scope.$watch("bigData.light", function(newVal,oldVal){
        if(oldVal !== newVal){

            localStorage.setItem("fan",newVal);

           $http.get("/rest/toggle/"+newVal+"")
                              .then(function(response){
                                  $scope.myWelcome = response.data.state;

                              });
        }

    });


});


app.controller('highChartCTLR',function($scope,$timeout){
    $scope.chartOptions = {
        title:{
            text:'Temperature data'
        },
        xAxis: {
            categories:['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec']
        },
        series:[{
            data:[29.9,71.5,106.4,129.2,144.0,176.0,135.6,148.5,216.4,194.1,95.6,54.4]
        }]
    };

$scope.minVal=0;
    // Sample data for pie chart
            //     $scope.pieData = [{
            //             data:[16],
            //             dataLabels: {
            //             format: '<div style="text-align:center"><span style="font-size:25px;color:black">{y}</span><br/>' + 
            //                 '<span style="font-size:12px;color:silver">km/h</span></div>'
            //             }
            // }];

        
      $timeout(function($scope){
       $scope.chart = new Highcharts.Chart(chartConfig, function(chart) {
       // chart.container.onclick = null;
       // chart.container.onmousedown = null;
       });
       $scope.chart.reflow();
    },2000);
    
    $scope.$watch('minVal', function(newVal) {
          if ($scope.chart) {
           $scope.chart.yAxis[0].update({
              min : newVal
           }, true);
           }
           });



});


app.directive("clock", function($interval ){

    return{
        scope:true,
        transclude:true,
        template:"<span class='clock'><span class='clock-text' ng-transclude></span><span class='clock-time'>{{date.now() | date: timeFormat}}</span></span>",
        link:function($s,$e, $a){
        $s.timeFormat = ($a.format ==='12')? 'hh:mm:ss a':'HH:mm:ss';
        $s.date = Date;
        $interval(null,1000);
        }
    };
});


app.directive('hcChart',function(){
    return {
        restrict: 'E',
        template:'<div></div>',
        scope:{
            options:'='
        },
        link: function(scope,element){
            Highcharts.chart(element[0], scope.options);
        }

    };

});

app.directive('hcPieChart', function () {
    return {
            restrict: 'E',
            template: '<div></div>',
            scope: {
                title: '@',
                data: '='
            },
            link: function (scope, element) {
                Highcharts.chart(element[0], {
                     chart: {
                    type: 'gauge',
                    plotBackgroundColor: null,
                    plotBackgroundImage: null,
                    plotBorderWidth: 0,
                    plotShadow: false
                },

                title: {
                    text: 'Temperature'
                },

                pane: {
                    startAngle: -150,
                    endAngle: 150,
                    background: [{
                        backgroundColor: {
                            linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                            stops: [
                                [0, '#FFF'],
                                [1, '#333']
                            ]
                        },
                        borderWidth: 0,
                        outerRadius: '109%'
                    }, {
                        backgroundColor: {
                            linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                            stops: [
                                [0, '#333'],
                                [1, '#FFF']
                            ]
                        },
                        borderWidth: 1,
                        outerRadius: '107%'
                    }, {
                        // default background
                    }, {
                        backgroundColor: '#DDD',
                        borderWidth: 0,
                        outerRadius: '105%',
                        innerRadius: '103%'
                    }]
                },

                // the value axis
                yAxis: {
                    min: 0,
                    max: 200,

                    minorTickInterval: 'auto',
                    minorTickWidth: 1,
                    minorTickLength: 10,
                    minorTickPosition: 'inside',
                    minorTickColor: '#666',

                    tickPixelInterval: 30,
                    tickWidth: 2,
                    tickPosition: 'inside',
                    tickLength: 10,
                    tickColor: '#666',
                    labels: {
                        step: 2,
                        rotation: 'auto'
                    },
                    title: {
                        text: 'km/h'
                    },
                    plotBands: [{
                        from: 0,
                        to: 120,
                        color: '#55BF3B' // green
                    }, {
                        from: 120,
                        to: 160,
                        color: '#DDDF0D' // yellow
                    }, {
                        from: 160,
                        to: 200,
                        color: '#DF5353' // red
                    }]
                },

                series: [{
                    name: 'Speed',
                    data: [10],
                    tooltip: {
                        valueSuffix: ' km/h'
                    }
                }]
                });
                        
            }
    };
});