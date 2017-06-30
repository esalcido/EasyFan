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
            <li><a href="#contact">Contact</a></li> 
            <li> <clock format="12" /></clock></li>
          -->
          </ul>

      </div><!--/.nav-collapse -->

    </div>
  </nav>

<div class="container" >

      <div class="starter-template">

      <div id="date-time" class="row">
        <div class="col-xs-2"></div>
        <div class="col-xs-8">
          <h3 style="color:#000"><clock format="12" /></clock></h3>
        </div>
        <div class="col-xs-2"></div>
        
      </div>


       <div  id="live data" class="row">
        <div class="col-xs-2"></div>
        <div class="col-xs-8" ng-controller="highChartCTLR">
          <div class="panel panel-primary">
            <div class="panel-heading">
            <p> <h1>Live Data</h1></p> 
            </div>
            <div class="panel-body">      
              <div id="chart" class="col-xs-6" >
                <!-- <hc-pie-chart title="Temperature"  >Placeholder for generic chart</hc-pie-chart> -->
                <h3>Temperature</h3>
                <div >
                    <img src="/assets/thermometer-medical-fever-temperature-control-tool_318-61723.jpg"  width="50" height="50" />
                    <h2>80 &deg; F</h2>
                </div>
              </div>

              <div id="humidity" class="col-xs-6" >
                <h3>Humidity</h3>
                <div>
                <img src="/assets/Science-Humidity-icon.png"  width="50" height="50" />
                </div>
                <div >
                    <h2>27 %</h2>
                </div>
              </div>


              
         </div>
        <div class="col-xs-2"></div>

       </div><!--end row-->



       <div id="control" class="row" ng-controller="myCtrl">
               <div class="col-xs-2"></div>
               <div class="col-xs-8" >
                
                <div class="panel panel-primary">
                  <div class="panel-heading">
                    <p> <h1>Control</h1></p></div>
                    <div class="panel-body">  
                          <div >
                                     <div class="btn-group" data-toggle="buttons">
                                        <div class="btn btn-primary" ng-model="bigData.light" uib-btn-checkbox>
                                         <img src="/assets/light-bulb-outline_318-49895.png"  width="50" height="50" />
                                         <label  >
                                             LIGHT
                                          </label>
                                        </div>
                                        <div class="btn btn-primary" ng-model="bigData.air" uib-btn-checkbox>
                                          <img src="/assets/air_conditioning_external-512.png"  width="50" height="50" />
                                          <label  >
                                             AIR
                                          </label>
                                        </div>
                                     </div>

                                     <div id="appliance-results" >
                                             <pre><code>{{ bigData | json }}</code></pre>
                                             <p>State:{{myWelcome}}</p>
                                     </div>
                          </div>
               </div>
               <div class="col-xs-2"></div>
        </div>

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