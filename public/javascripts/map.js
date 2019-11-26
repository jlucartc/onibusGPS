var xhttp = new XMLHttpRequest(); 


xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
    console.log(this.responseText);
  }
};
xhttp.open("GET","https://bus_gps_data.data.thethingsnetwork.org/api/v2/devices", true);

//xhttp.setRequestHeader('Accept','application/json');
xhttp.setRequestHeader('Content-Type', 'application/json');
xhttp.setRequestHeader('Authorization','Basic key ttn-account-v2.IFJLbrAmGz8RoPRF-_DF0MRiIp-hmtB2it2HRdn9_yA');

xhttp.send(); 

var layer = new L.StamenTileLayer("toner");
var map = new L.Map("mapid", {
    center: new L.LatLng(-3.7172200, -38.5430600),
    zoom: 12
});
map.addLayer(layer);

var marker = L.marker([-3.717, -38.543]).addTo(map);
marker.bindPopup("<b>Hello world!</b><br>I am a popup.");

function getDataFromTTN(){

	//

}

function saveToMongo(){

	//

}
