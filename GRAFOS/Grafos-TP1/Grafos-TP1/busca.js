
let tempo, cor = [];
let d = []; pi = [];
let tempo_chegada = [];
let tempo_finalizacao = [];
let caminhoV = [];

class Busca {

    busca() {
        let x = document.getElementById("op").value;
        let u = document.getElementById("u").value;
        let v = document.getElementById("v").value;
        let result;
        //let x = 0, u = 4, v =1;
        if (x == 0) result = this.caminhoDFS(grafo, u, v);
        else if (x == 1) this.caminhoBFS(grafo, u, v);
        else console.error();
        result = caminhoV;
        return result;
    }

    chamarDFS(grafo) {
        let raiz = prompt("Entre com o vértice raíz para a DFS: ");
        //let raiz = 2; 
        this.dfs(grafo, raiz);
        let txtDesc = " ", txtFin = " ";
        for (let i = 0; i < grafo.length; i++) {
            txtDesc = txtDesc + "O vértice " + i + " foi descoberto no instante " + tempo_chegada[i] + "<br>";
            txtFin = txtFin + "O vértice " + i + " foi finalizado no instante " + tempo_finalizacao[i] + "<br>";
        }
        document.getElementById("dfs_resultado").innerHTML = txtDesc + "<br>" + txtFin;
    }

    dfs(grafo, raiz) {

        tempo = 0;
        for (let u = 0; u < grafo.length; u++) {
            cor[u] = 'BRANCO';
        }
        for (let u = raiz; u < grafo.length; u++) {
            if (cor[u] == 'BRANCO') {
                this.dfs_visit(grafo, u, null, null);
            }
        }
        for (let u = 0; u < raiz; u++) {
            if (cor[u] == 'BRANCO') {
                this.dfs_visit(grafo, u, null, null);
            }
        }
    }

    dfs_visit(grafo, u, dest, result) {
        cor[u] = 'CINZA';
        if (dest != null) {
            caminhoV.push(u);
            if (u == dest) { //bugado
                return;
            }
        }
        tempo_chegada[u] = tempo++;
        for (let v = 0; v < grafo.length; v++) {
            if (grafo[u][v] != 0) {
                if (cor[v] == 'BRANCO') {
                    this.dfs_visit(grafo, v, dest, result);
                }
            }
        }
        tempo_finalizacao[u] = tempo++;
        cor[u] = 'PRETO';
    }

    caminhoDFS(grafo, u, v) {
        let result;
        for (let x = 0; x < grafo.length; x++) {
            cor[x] = 'BRANCO';
        }
        
        this.dfs_visit(grafo, u, v, result);
        
    }


    chamarBFS(grafo) {
        let raiz = prompt("Entre com o vértice raíz para a BFS: ");
        //let raiz = 0;
        this.bfs(grafo, raiz);
        let txtDist = "<h4>Vértice  ->  Distância até a raiz(" + raiz + ")<h4> <br>";
        for (let i = 0; i < grafo.length; i++) {
            if (d[i] == Number.MAX_SAFE_INTEGER) txtDist = txtDist + i + "   ->     " + "n/a" + "<br>";
            else txtDist = txtDist + i + "   ->     " + d[i] + "<br>";
        }
        document.getElementById("bfs_resultado").innerHTML = txtDist;
        //let caminho = this.caminhoBFS(grafo);
        console.log(pi);

    }


    bfs(grafo, raiz, dest) {

        for (let i = 0; i < grafo.length; i++) {
            cor[i] = 'BRANCO';
            d[i] = Number.MAX_SAFE_INTEGER;
            pi[i] = null;
        }
        cor[raiz] = 'CINZA';
        d[raiz] = 0;

        let fila = new Queue();
        fila.enqueue(raiz);
        while (!fila.isEmpty()) {
            let u = fila.dequeue();
            for (let v = 0; v < grafo.length; v++) {
                if (grafo[u][v] != 0) {
                    if (cor[v] == 'BRANCO') {
                        cor[v] = 'CINZA';
                        d[v] = d[u] + 1;
                        pi[v] = u;
                        fila.enqueue(v);
                        if (dest != null) {
                            caminhoV.push(u);
                            if (u == dest) document.getElementById("caminho_result").innerHTML = caminhoV;
                        }
                    }
                }
            }
            cor[u] = 'PRETO';
        }

    }

    caminhoBFS(grafo, u, v) {   //não ta funcionando pq pi[] (pai) está saindo errado
        this.bfs(grafo);
        console.log(caminhoV);
    }
    
}



class Queue {
    // Array is used to implement a Queue 
    constructor() {
        this.items = [];
    }

    // Functions to be implemented 
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        if (this.isEmpty()) {
            return console.error();

        }
        return this.items.shift();
    }
    // front() 
    isEmpty() {
        return this.items.length == 0;
    }
    // printQueue() 
}

// let obj = new Busca();
// obj.chamarBFS(grafo);
// //obj.busca();
