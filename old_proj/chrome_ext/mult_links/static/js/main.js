var button = document.getElementById("testing")
var button2 = document.getElementById("clip_but")

var list_links = [];
//button.addEventListener("click", function(){var win = window.open("","","width=500,height=500");});
button.addEventListener("click", function(){
  for(c1 = 0; c1 < list_links.length;c1++){
    var win = window.open(list_links[c1],"","");
  }
});

button2.addEventListener("click", function(){
  var link_link = document.getElementById("link_text").value;
  list_links.push(link_link);
  console.log(list_links);
  var link_hold = document.getElementById("link_holder");
  var node = document.createElement("LI");
  link_hold.innerHTML=printList(list_links);
  //console.log(clipboard);
});


var printList = function printList(list_temp){
  var text_temp = "";
  for(c1 = 0; c1 < list_temp.length; c1++){
    text_temp += list_temp[c1] + "<br>";
  };
  return text_temp;
};
