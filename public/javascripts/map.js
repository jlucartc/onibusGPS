
var data = document.getElementById("lat").innerHTML;

console.log(data);



var layer = new L.StamenTileLayer("toner");
var map = new L.Map("mapid", {
    center: new L.LatLng(-3.7172200, -38.5430600),
    zoom: 12
});
map.addLayer(layer);

var marker = L.marker([-3.717, -38.543]).addTo(map);
marker.bindPopup("<b>Hello world!</b><br>I am a popup.");

function getData(){

	//

}

function saveToMongo(){

	//

}
