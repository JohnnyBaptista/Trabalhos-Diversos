
package Classes;

import java.awt.image.ImageObserver;
import java.io.Serializable;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 * A classe Configuracao possui os dados referentes ao nome dos arquivos usados
 * pelo sistema e a quantidade de dias que alunos e professores podem
 * permanecerem com livros.
 * 
 * @author Matheus Prachedes, Eymar Lima, Carlos Henrique.
 */
public class Configuracao implements Serializable{

    /**
     * Nome do arquivo usado para salvar os livros cadastrados.
     */
    private String arquivoLivros;
    
    /**
     * Nome do arquivo usado para salvar os usuários cadastrados.
     */
    private String arquivoUsuarios;
    
    /**
     * Nome do arquivo usado para salvar os empréstimos cadastrados.
     */
    private String arquivoEmprestimos;
    
    /**
     * Quantidade de dias que um aluno pode ficar com um livro.
     */
    private int diasAlunos;
    
    /**
     * Quantidade de dias que um professor pode ficar com um livro.
     */
    private int diasProfessor;
    /**
     * Variável usada pela interface Serializable.
     */
    private static final long serialVersionUID = 1L;
    
    /**
     * Único construtor da classe Configuracao, inicializa as variáveis de 
     * configurações com os valores default.
     */
    public Configuracao(){
        arquivoLivros = "livros.arq";
        arquivoEmprestimos = "emprestimos.arq";
        arquivoUsuarios = "usuarios.arq";
        diasAlunos = 10;
        diasProfessor = 20;
    }
    
    /**
     * @return Retorna a quantidade de dias que um aluno pode ficar 
     *         com um livro.
     */
    public int getDiasAlunos(){
        return diasAlunos;
    }
    
    /**
     *
     * @return Retorna a quantiade de dias que um professor pode ficar
     *         com um livro.
     */
    public int getDiasProfessor(){
        return diasProfessor;
    }
    
    /**
     *
     * @return Retorna o nome do arquivo usado para salvar os livros
     *         cadastrados.
     */
    public String getArquivoLivros() {
        return arquivoLivros;
    }

    /**
     *
     * @return Retorna o nome do arquivo usado para salvar os usuários
     *         cadastrados.
     */
    public String getArquivoUsuarios() {
        return arquivoUsuarios;
    }

    /**
     *
     * @return Retorna o nome do arquivo usado para salvar os empréstimos
     *         cadastrados.
     */
    public String getArquivoEmprestimos() {
        return arquivoEmprestimos;
    }

    /**
     *
     * @param arquivoLivros Nome do novo arquivo de livros.
     */
    public void setArquivoLivros(String arquivoLivros) {
        this.arquivoLivros = arquivoLivros;
    }

    /**
     *
     * @param arquivoUsuarios Nome do novo arquivo de usuários. 
     */
    public void setArquivoUsuarios(String arquivoUsuarios) {
        this.arquivoUsuarios = arquivoUsuarios;
    }

    /**
     *
     * @param arquivoEmprestimos Nome do novo arquivo de empréstimos.
     */
    public void setArquivoEmprestimos(String arquivoEmprestimos) {
        this.arquivoEmprestimos = arquivoEmprestimos;
    }

    /**
     *
     * @param diasAlunos Nova quantidade de dias que um aluno pode ficar com
     *                   um livro.
     */
    public void setDiasAlunos(int diasAlunos) {
        this.diasAlunos = diasAlunos;
    }

    /**
     *
     * @param diasProfessor Nova quantidade de dias que professor pode ficar
     *                      com um livro.
     */
    public void setDiasProfessor(int diasProfessor) {
        this.diasProfessor = diasProfessor;
    }
    
    
}
