<!doctype html>

<html lang="en" >
<head>
  <meta charset="utf-8">

  <title>The Easy Fan</title>
  <meta name="description" content="The HTML5 Herald">
  <meta name="author" content="SitePoint">

  <link  rel="stylesheet" type="text/css" href="/webjars/bootstrap/3.3.1/css/bootstrap.min.css">
  <link href="/css/starter-template.css" rel="stylesheet">
  <link href="/css/style.css" rel="stylesheet">

  <!--[if lt IE 9]>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.3/html5shiv.js"></script>
  <![endif]-->



</head>

<body ng-app="myApp">

  <nav class="navbar navbar-inverse navbar-fixed-top">
    <div class="container">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="#">Project Flow Whole</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
          <ul class="nav navbar-nav">
            <li class="active"><a href="#">Home</a></li>
            <!-- <li><a href="#about">About</a></li>
            <li><a href="#contact">Contact</a></li> -->
            <li> <clock format="12" /></clock></li>
          </ul>

      </div><!--/.nav-collapse -->

    </div>
  </nav>

<div class="container" >

      <div class="starter-template">

       <div  id="live data" class="row">
        <div class="col-xs-2"></div>
        <div class="col-xs-8">
            <p> <h1>Live Data</h1></p>       

             <div id="chart" class="col-xs-4" ng-controller="highChartCTLR">
                <!-- <hc-pie-chart title="Temperature" data="pieData" > --><hc-pie-chart title="Temperature"  >Placeholder for generic chart</hc-pie-chart>

               <!--  <hc-pie-chart class="col-xs-4" title="Humidity" data="pieData" >Placeholder for generic chart</hc-pie-chart> -->

             </div>
        </div>
        <div class="col-xs-2"></div>

       </div>
       <div id="control" class="row">
               <div class="col-xs-2"></div>
               <div class="col-xs-8" >
                <p> <h1>Control</h1></p>
                    <div ng-controller="myCtrl">
                               <div class="btn-group" data-toggle="buttons">
                                   <label class="btn btn-primary" ng-model="bigData.light" uib-btn-checkbox>
                                       LIGHT
                                    </label>
                                    <label class="btn btn-primary" ng-model="bigData.air" uib-btn-checkbox>
                                       AIR
                                    </label>
                               </div>

                               <div id="appliance-results" >
                                       <pre><code>{{ bigData | json }}</code></pre>
                                       <p>State:{{myWelcome}}</p>
                               </div>
               </div>
               <div class="col-xs-2"></div>
        </div>

      <!--  <div id="temp-data" class="col-lg-12" >
        <h3>DATA: </h3>
        <pre><code>
            <div id="temp" class="col-lg-6">temp: </div>
            <div id="humidity" class="col-lg-6">humidity: </div>
       </code> </pre>
        </div>-->


      </div>
    </div><!-- /.container -->





<script src="/webjars/angularjs/1.4.7/angular.min.js"></script>
<script src="/webjars/angular-ui-bootstrap/2.2.0/ui-bootstrap.js"></script>
<script src="/js/directives/directives.js"></script>
<!-- link for highcharts -->
 <script type="text/javascript" src="https://code.highcharts.com/highcharts.js"></script>
 <script src="https://code.highcharts.com/highcharts-more.js"></script>
 <script type="text/javascript" src="https://code.highcharts.com/modules/exporting.js"></script>
<script src="https://code.highcharts.com/modules/solid-gauge.js"></script>
<!--<script src="/webjars/bootstrap/3.3.1/js/bootstrap.min.js"></script>-->



<script src="js/app.js"></script>


</body>
</html>