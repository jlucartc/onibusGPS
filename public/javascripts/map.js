
var data = JSON.parse(document.getElementById("data").innerHTML);

console.log(data);


var layer = new L.StamenTileLayer("toner");
var map = new L.Map("mapid", {
    center: new L.LatLng(-3.747268,-38.575144),
    zoom: 14
});
map.addLayer(layer);

for(var i = 0; i < data.length; i++){

	var coords = data[i].raw.split("/");
	console.log(coords);
	var marker = L.marker([parseFloat(coords[0]),parseFloat(coords[1])]).addTo(map);

}

//var marker = L.marker([-3.717, -38.543]).addTo(map);
//marker.bindPopup("<b>Hello world!</b><br>I am a popup.");

function getData(){

	//

}

function saveToMongo(){

	//

}
