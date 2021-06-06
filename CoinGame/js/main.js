$("#draggable1").draggable();
$("#draggable2").draggable();
$("#draggable3").draggable();
$("#draggable4").draggable();
$("#draggable5").draggable();
$("#draggable6").draggable();
$("#draggable7").draggable();
$("#draggable8").draggable();
$("#draggable9").draggable();
$("#draggable10").draggable();
$("#draggable11").draggable();
$("#draggable12").draggable();
$("#draggable13").draggable();
$("#draggable14").draggable();
$("#draggable15").draggable();
$("#draggable16").draggable();

window.onresize = function() {
  getGridPosition();
};

// START VARIABILE GLOBALE //

// numarul de fise
var numar_fise = 10;
// numarul de linii/coloane din grid
var numar_linii_coloane = numar_fise / 2;

// size of grid element
var cell_size = 70; //px

// matricea grila joc A(nxn)
// retine 1 pentru celulele ocupate, 0 pentru cele libere
var matriceaA = Array(numar_linii_coloane).fill(null).map(() => Array(numar_linii_coloane).fill(0));

/// matricea X(numar_fise_x_3) retine plasarea fiecarui element in grid
/// col 1 retine nr element (fisa)
/// col 2 retine nr liniei
/// col 3 retine nr coloanei
var X = Array(numar_fise).fill(null).map(() => Array(3).fill(-1));

// vectorul erori pe linii B(n)
// retine 1 pe linia (0-4) pe care sunt erori (0 fise, 1 fisa , > 2 fise)
var matriceaB = Array(numar_linii_coloane).fill(1);

// vectorul erori pe coloane C(n)
// retine 1 pe coloana (0-4) pe care sunt erori (0 fise, 1 fisa , > 2 fise)
var matriceaC = Array(numar_linii_coloane).fill(1);

// vectorul erori pe diagonale D(2)
// retine 1 pe diagonala (0=diagonala principala, 1=diagonala secundara) pe care sunt erori (0 fise, 1 fisa , > 2 fise)
var matriceaD = Array(2).fill(1);

var linia = 0;
var coloana = 0;
var numar_incercari = 0;

var nr_iteratii = 0;
var execution_time = 0;
var preview_element = 0;
var preview_line = 0;
var preview_column = 0;

// min/max dimension of grid, for draggabled elements
var grid_X_min = 0;
var grid_X_max = 0;
var grid_Y_min = 0;
var grid_Y_max = 0;

// variabile pentru corectat pozitia fiselor in grila
var margin_left = 0;
var margin_top = 0;

// numarul de mutari
var numar_mutari = 0;

// variabile pentru retinerea ultimei pozitii a unei fise in grila
// in cazul in care se muta in interiorul grilei
var old_line = 0;
var old_column = 0;

// pozitia mouse-ului
var mousePosition = {};

//
var z_index = 100;

var start = new Date().getTime();

///* START FUNCTIONS *///

function onInit(numarFise) {

  numar_fise = numarFise;
  numar_linii_coloane = numar_fise / 2;

  cell_size = 70; //px

  matriceaA = Array(numar_linii_coloane).fill(null).map(() => Array(numar_linii_coloane).fill(0));

  X = Array(numar_fise).fill(null).map(() => Array(3).fill(-1));

  matriceaB = Array(numar_linii_coloane).fill(1);
  matriceaC = Array(numar_linii_coloane).fill(1);
  matriceaD = Array(2).fill(1);

  linia = 0;
  coloana = 0;
  numar_incercari = 0;

  nr_iteratii = 0;
  execution_time = 0;
  preview_element = 0;
  preview_line = 0;
  preview_column = 0;

  grid_X_min = 0;
  grid_X_max = 0;
  grid_Y_min = 0;
  grid_Y_max = 0;

  margin_left = 0;
  margin_top = 0;

  numar_mutari = 0;

  old_line = 0;
  old_column = 0;
  mousePosition = {};

  z_index = 100;

  getGridPosition();
}

function getGridPosition() {

  var grid = document.getElementById("grid");
  var grid_pos = getPosition(grid);
  margin_left = grid_pos.X;
  margin_top = grid_pos.Y;

  grid_X_min = margin_left;
  grid_Y_min = margin_top;

  grid_X_max = margin_left + numar_linii_coloane * cell_size;
  grid_Y_max = margin_top + numar_linii_coloane * cell_size;
}

/// pozitia mouse-ului la click
function getMousePosition() {
  var x_m = event.clientX; // Get the horizontal coordinate
  var y_m = event.clientY; // Get the vertical coordinate

  return {
    X: x_m,
    Y: y_m
  };
}

/// afla pozitia unui element (fisa)
function getPosition(element) {
  var rect = element.getBoundingClientRect();

  return {
    X: rect.left,
    Y: rect.top
  };
}
function check_restart(){

  if (confirm('Are you sure you want to restart?')) {
    console.log('Yes I am sure' );
  } else {
    console.log('Cancel');
  }

  restart();
}
/// restart the game
function restart() {

  document.getElementById('checkRestart').innerHTML = '';

  //repune toate fisele in pozitia initiala
  for (var i = 1; i <= numar_fise; i++) {
    var element = document.getElementById("draggable" + i);
    element.style.left = 0;
    element.style.top = 0;
  }

  // initializeaza matricea A
  // initializeaza matricea B
  // initializeaza matricea C
  for (var i = 0; i < numar_linii_coloane; i++) {
    for (var j = 0; j < numar_linii_coloane; j++) {
      matriceaA[i][j] = 0;
    }
    matriceaB[i] = 0;
    matriceaC[i] = 0;
  }

  // initializeaza matricea D
  for (var i = 0; i < 2; i++) {
    matriceaD[i] = 0;
  }

  // initializeaza matricea X
  X = Array(numar_fise).fill(null).map(() => Array(3).fill(-1));

  // initializeaza variabila mutari
  numar_mutari = 0;
  document.getElementById('mutari').innerHTML = 'Mutari: #';

  // sterge masajul
  document.getElementById('done').innerHTML = '';
  document.getElementById('errors').innerHTML = '';

  history_moves = [];
}

/// afla celula in care s-a dat click
/// la mutarea unei fise de pe grila
/// pentru a pune in matricea A valoarea 0 in celula
/// din care se muta fisa
function mouseDown(el) {

  z_index += 100;
  var element = document.getElementById("draggable" + el);
  element.style.zIndex = z_index;

  mousePosition = getMousePosition();

  var linia = parseInt((mousePosition.Y - grid_Y_min) / cell_size) + 1;
  var coloana = parseInt((mousePosition.X - grid_X_min) / cell_size) + 1;

  // retine pozitia din care pleaca fisa in variabilele old_line, old_column
  // pentru a o repune in aceasta pozitie daca este necesar
  if (mousePosition.X <= grid_X_min || mousePosition.Y <= grid_Y_min) {
    old_line = 0;
    old_column = 0;
  } else {

    // set 0 into matrix A
    if (linia >= 1 && coloana >= 1) {
      if (matriceaA[linia - 1][coloana - 1] == 1)
        matriceaA[linia - 1][coloana - 1] = 0;
    }

    old_line = linia;
    old_column = coloana;
  }

}

var history_moves = [];

/// aseaza fisa in grila
function mouseUp(el) {

  mousePosition = getMousePosition();

  var element = document.getElementById("draggable" + el);

  var pos = getPosition(element);

  // verifica daca pozitia in care a ajuns fisa este pe grila
  // daca nu, repune fisa in pozitia anterioara
  if (pos.X <= grid_X_min || pos.X > grid_X_max || pos.Y <= grid_Y_min || pos.Y > grid_Y_max) {

    if(X[el-1][0]!=-1 && X[el-1][1]!=-1)
    {
      history_moves.push({old_line: old_line, old_column: old_column, line: -1, column: -1, el: el});
      numar_mutari ++;
    }

    element.style.left = 0;
    element.style.top = 0;
    document.getElementById('mutari').innerHTML = 'Mutari: ' + numar_mutari;
    return;
  }

  // afla linia si coloana in care trebuie plasata fisa
  var linia = parseInt((mousePosition.Y - grid_Y_min) / cell_size) + 1;
  var coloana = parseInt((mousePosition.X - grid_X_min) / cell_size) + 1;

  if (linia < 0 || linia > numar_linii_coloane || coloana < 0 || coloana > numar_linii_coloane) {
    element.style.left = 0;
    element.style.top = 0;

    return;
  }


  // verifica daca celula in care ajunge fisa este ocupata
  // daca da repune fisa in pozitia anterioara
  if (matriceaA[linia - 1][coloana - 1] == 1) {
    if (old_line == 0 && old_column == 0) {
      element.style.left = 0;
      element.style.top = 0;

      return;
    }

    aseazaFisaInGrila(el, element, old_line, old_column);

    return;
  }

  // set 1 into matrixA = celula ocupata
  if (linia >= 1 && coloana >= 1) {
    matriceaA[linia - 1][coloana - 1] = 1;
  }

  if ((linia != old_line) || (coloana != old_column)) {

    X[el-1][0]=linia-1;
    X[el-1][1]=coloana -1;
    numar_mutari++;
    document.getElementById('mutari').innerHTML = 'Mutari: ' + numar_mutari;
  }
  history_moves.push({old_line: old_line, old_column: old_column, line: linia, column: coloana, el: el});
  aseazaFisaInGrila(el, element, linia, coloana);
  verificaDacaEsteSolutie();

  // verifica cate fise a pus in grid
  var fise_jucate = getFiseJucate();

  // va afisa mesaj doar dupa ce a pus toate fisele pe grila
  if (fise_jucate >= numar_fise) {
    afiseazaMesaj();
  }

  console.table(X); // to be deleted
}

function aseazaFisaInGrila(el, element, linia, coloana) {
  // variabile pentru corectarea pozitiei fiselor in grila

  margin_left = (-80 -numar_fise*1.36) - ((el <= numar_fise / 2) ? (el - 1) : (el - 1 - numar_fise / 2)) * 60;
  margin_top = (el <= numar_fise / 2) ? 67 : 2;

  var new_x = margin_left + cell_size * coloana;
  var new_y = margin_top + cell_size * linia;

  element.style.left = new_x + "px";
  element.style.top = new_y + "px";
}

/// verifica daca este solutie
function verificaDacaEsteSolutie() {
  var checkLinie = true;
  var checkColoana = true;
  var checkDiag;
  for (var i = 0; i < numar_linii_coloane; i++) {
    checkLinie = checkLinie && verificaPeLinie(i);
    checkColoana = checkColoana && verificaPeColoana(i);
  }
  checkDiag = verificaSecundara() && verificaPrincipala();
  if (checkLinie && checkColoana && checkDiag) {
    var end = new Date().getTime();
    // Now calculate and output the difference
    execution_time = end - start;
    document.getElementById('done').innerHTML = '<font color="#FF0000"><b>SOLVED!</b> in ' + execution_time / 1000 + ' s';
    document.getElementById('errors').innerHTML = '';

  } else {
    var erori = numar_erori();
    document.getElementById('done').innerHTML = '';
    document.getElementById('errors').innerHTML = '<font color=red><b>Erori: </b>' + erori + '</font>';
  }
}

function numar_erori() {
  var erori = 0;
  for (var i = 0; i < numar_linii_coloane; i++) {
    if (!verificaPeLinie(i))
      erori++;
    if (!verificaPeColoana(i))
      erori++;
  }

  if (!verificaPrincipala())
    erori++;
  if (!verificaSecundara())
    erori++;
  return erori;
}

function verificaPeLinie(index_linie) {
  var suma = 0;
  for (var j = 0; j < numar_linii_coloane; j++) {
    suma += matriceaA[index_linie][j];
  }
  if (suma == 2)
    return true;
  return false;
}

function verificaPeColoana(index_coloana) {
  var suma = 0;
  for (var i = 0; i < numar_linii_coloane; i++) {
    suma += matriceaA[i][index_coloana];
  }
  if (suma == 2)
    return true;
  return false;
}

function verificaPrincipala() {
  var sumaPrincipala = 0;
  for (var i = 0; i < numar_linii_coloane; i++)
    sumaPrincipala += matriceaA[i][i];

  if (sumaPrincipala == 2)
    return true;
  return false;
}

function verificaSecundara() {
  var sumaSecundara = 0;
  for (var i = 0; i < numar_linii_coloane; i++)
        sumaSecundara += matriceaA[i][numar_linii_coloane - i - 1];

  if (sumaSecundara == 2)
    return true;
  return false;
}

function getFiseJucate() {

  var fise_jucate = 0;
  for (var i = 0; i < numar_linii_coloane; i++) {
    for (var j = 0; j < numar_linii_coloane; j++) {
      if (matriceaA[i][j] === 1)
        fise_jucate++;
    }
  }

  return fise_jucate;
}


/// rezolva jocul pornind de la configuratia data de jucator
function solve() {

  // ?

  // Remember when we started




  var start = new Date().getTime();
  var end = new Date().getTime();
    execution_time = end - start;

    document.getElementById('done').innerHTML = '<font color="#FF0000"><b>SOLVED!</b> in ' + execution_time + ' ms</font>';
    document.getElementById('errors').innerHTML = '';

    return;
  }


function undo() {
  if (history_moves.length > 0) {

    var last_move = history_moves[history_moves.length - 1];
    var element = document.getElementById("draggable" + last_move.el);
    if (last_move.line >= 1 && last_move.column >= 1) {

     matriceaA[last_move.line - 1][last_move.column - 1] = 0;
    }

    if(last_move.old_line === 0 && last_move.old_column === 0){
      element.style.left = 0;
      element.style.top = 0;
    }
    else {
      matriceaA[last_move.old_line-1][last_move.old_column -1]=1
      aseazaFisaInGrila(last_move.el, element, last_move.old_line, last_move.old_column);
    }

    X[last_move.el][0]=last_move.old_line;
    X[last_move.el][1]=last_move.old_column;
    history_moves.pop();
    numar_mutari--;
    document.getElementById('mutari').innerHTML = 'Mutari: ' + numar_mutari;
    verificaDacaEsteSolutie();

  }
}

/// aseaza fisele in grila in functie de configuratia matricei A
function aseazaFiseleInGrila() {
  var k = 1; // prima fisa

  for (var i = 0; i < numar_linii_coloane; i++) {
    for (var j = 0; j < numar_linii_coloane; j++) {
      if (matriceaA[i][j] === 1) {
        var element = document.getElementById("draggable" + k);
        aseazaFisaInGrila(k, element, i + 1, j + 1);
        k++; // urmatoarea fisa
      }
    }
  }
}

var current_className_fisa = 'draggable';
function changeFisa(model) {
  if (model) {
    for (var i = 1; i <= numar_fise; i++) {
      var element = document.getElementById("draggable" + i);
      element.className = element.className.replace(current_className_fisa, model);
    }
    current_className_fisa = model;
  }
}
