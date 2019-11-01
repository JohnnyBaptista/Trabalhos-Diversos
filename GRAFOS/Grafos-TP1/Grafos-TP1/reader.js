const input = document.getElementById('txtToRead');
let objBusca = new Busca();
let grafo;
input.addEventListener('change', (e) => {
    const reader = new FileReader();
    reader.onload = () => {
        const lines = reader.result.split('\n').map((line) => {
            return line.split(' ');
        });
        grafo = createMatrizAdj(lines);
        console.log(grafo);
        
    }
    reader.readAsText(input.files[0]);
}, false);


const createMatrizAdj = (array) => {
    let def = array[0];
    let size = array[1];
    let aux = [];
    let matriz = [];
    matriz = vai(matriz, size);
    for (let i = 0; i < size; i++) {
        if (typeof matriz[i] == 'undefined') matriz[i] = new Array();
        for (let j = 0; j < size; j++) {
            matriz[i].push(0);
        }

    }

    for (i = 2; i < array.length; i++) {
        for (let j = 0; j < array.length; j++) {
            aux.push(parseInt(array[i][j]));
        }
    }

    const connections = aux.filter(value => !Number.isNaN(value)); //retira os NaN
    for (let i = 0; i < connections.length - 2; i += 3) {
        let de = connections[i];
        let para = connections[i + 1];
        let peso = connections[i + 2];
        // if (typeof matriz[de] == 'undefined') matriz[de] = new Array();
        matriz[de][para] = peso;
    }
    matriz[0].pop();
    //console.log(matriz);
    return matriz;
}

const vai = (matriz, qtvert) => {
    var matriz = [qtvert];
    matriz.fill(0, 0, qtvert);
    for (let val in matriz) {
        matriz[val] = [qtvert];
        matriz[val].fill(0, 0, qtvert);
    }
    return matriz;
}



/* 
0: ["0"]
1: ["5"]
2: (3) ["0", "2", "4"]
3: (3) ["0", "4", "60"]
4: (3) ["0", "3", "23"]
5: (3) ["2", "3", "4"]
6: (3) ["3", "1", "10"]
7: (3) ["4", "2", "15"]
8: [""]
*/


/*
0
5
0 2 4
0 4 60
0 3 23
2 3 4
3 1 10
4 2 15
 */