# Trabalhos Ciência da Computação 
Códigos prontos e projetos de trabalhos da faculdade de ciência da computação FCT-UNESP Prudente
Livre para uso e estudo!

### Compartilhe também!
> Seu colaboração é muito importante para ajudar os alunos de computação a estudar e se tornarem excelentes programadores.

O repositório estará livre para todos que quiserem adicionar seu trabalho, exercício ou projeto final de alguma matéria.
Nos ajude a criar um acervo para os futuros calouros da computa, o curso que tanto amamos!

### Como contribuir?

> É muito fácil, você só precisa de dois requisitos:
>
> 1. [Git](https://git-scm.com/downloads) instalado no seu PC.
> 2. Um projeto/exercício/trabalho completo (ou não, afinal a comunidade pode contribuir para seu trabalho)

Siga os seguintes passos para contribuir com o repositório:

#### 1. Faça um fork do repositório

Apenas clique no botão de _**fork**_ na parte superior do site 

![Fork do Repositório](/public/imgs/fork.png "Forkando um repositório")

#### 2. Clone seu fork

Agora iremos virar **HACKERMANS** 

<img align="right" src="https://media.giphy.com/media/RyXVu4ZW454IM/giphy.gif">

###### 1. Abra seu terminal de preferência e acesse alguma pasta conforme mostrado abaixo:

- linkar imgs mostrando passo a passo

###### 2. Clone o repositório

Copie o link do repositório

![Clone do Repositório](/public/imgs/clone.png "Clonando um repositório")

Em algum diretório do seu computador você vai utilizar o link copiado e executar o código no seu terminal:

```bash
git clone <link copiado>
```

Então, por exemplo, em meu computador eu escreveria o comando:

```bash
git clone https://github.com/JohnnyBaptista/Trabalhos-Diverso-FCTUNESP.git
```

Agora acesse a pasta Trabalhos-Diverso-FCTUNESP

```bash
cd  Trabalhos-Diversos-FCTUNESP
```

###### 3. Adicione o seu trabalho

Seguindo a ***estrutura de pastas*** do repositório, procure a matéria que você deseja adicionar e coloque o copie/salve o arquivo para dentro dela.

###### 4. Crie uma ramificação (branch)

As **branches** serão nossa ferramenta para o controle dos trabalhos, códigos e alterações que estão entrando no repositório.
Para criar uma branch, iremos executar no terminal o comando:

```bash
git checkout -b adc-meu-trabalho
``` 
ou 
```bash
git checkout -b adc-meu-exercicio 
``` 
> Usaremos algo nesse formato para identificar o que a branch está controlando

Então, por exemplo se eu quiser adicionar um trabalho de Programação Orientada a Objetos, posso fazer algo do tipo:

```bash
git checkout -b adc-trabalho-poo
```

###### 5. "Commitar" e "pushar" os arquivos adicionados/modificados

Antes de enviar é preciso ***"commitar"*** os arquivos adicionados/modificados para o git entender o que você está fazendo.
Execute:

```bash
git add . 
git commit -m "Adicionando trabalho de poo"
```

> Use os commits para identificar as alterações que você está fazendo nos arquivos e pastas

Após isso, podemos enviar para o repositório remoto as alterações

```bash
git push origin adc-trabalho-poo
```

###### 6. Crie um Pull Request (PR)

Quando terminarmos todos esses passos, basta agora criar um pull request para solicitarmos a insersão dos arquivos no repositório de origem. Muitas vezes o próprio github já percebe quando existe uma branch que acabou de ser "pushada", e irá sugerir você comparar e criar a PR. Mas, utilizaremos o "New pull request" da aba de pull request como segue as imagens

#### 1. Entre na aba de PR
![Aba de Pull Requests](/public/imgs/PR1.png "Aba de PR")

#### 2. Crie uma nova PR
![Criando uma PR](/public/imgs/PR2.png "Criando uma PR")

#### 3. Selecione a sua branch