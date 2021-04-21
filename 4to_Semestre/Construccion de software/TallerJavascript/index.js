var counter = 1;
function changeImage() {
    counter > 4 ? counter = 1 : counter++; 
    document.getElementById("carousel").src = "./img/carousell/"+counter+".jpg";
}

function changeImageBack() {
    if(counter> 1){
        counter--;
        document.getElementById("carousel").src = "./img/carousell/"+counter+".jpg";
    }else{
        counter =1
    }
}

function changePies(){
    document.getElementById("altura").innerHTML  = "6.069554 ft"
}

function changeMetros(){
    document.getElementById("altura").innerHTML  = "185 cm"
}

function showMore(){
    var x = document.getElementById("moreContent");
    if (x.style.display === "none"){
      x.style.display = "block";
      document.getElementById("toggler").innerHTML  = "Esconder información ▲"
    } else {
      x.style.display = "none";
      document.getElementById("toggler").innerHTML  = "Ver más información ▼"
    } 
}