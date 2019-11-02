package Classes.usuarios;

import Classes.usuarios.Usuario;
import java.util.ArrayList;

/**
 * Subclasse de usuário.
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique.
 */
public class Aluno extends Usuario{
    /**
     * Nome do curso que o alunos está cursando.
     */
    protected String curso;
    /**
     * Quantidade a anos que o aluno está no curso.
     */
    protected int ano;
    /**
     * Constrói um aluno com os dados especificados.
     * @param codUsuario Código de referência do usuário.
     * @param nome Nome do usuário.
     * @param diasEmprestimo Quantos dias o usuário pode ficar com um livro emprestado.
     * @param curso Nome do curso que o aluno está cursando.
     * @param ano Quantidade de anos que o aluno está no curso.
     */
    public Aluno(String codUsuario, String nome, int diasEmprestimo,String curso,int ano) {
        super(codUsuario, nome, diasEmprestimo);
        this.curso = curso;
        this.ano = ano;
    }
    /** 
     * @return Retorna o nome do curso do aluno.
     */
    public String getCurso(){
        return curso;
    }
    /**
     * @return Retorna a quantidade de anos que o aluno está na faculdade. 
     */
    public int getAno(){
        return ano;
    }
    /**
     * @param curso Nome do novo curso do aluno. 
     */
    public void setCurso(String curso){
        this.curso = curso;
    }
    /**
     * @param ano Nova quantidade de anos que o aluno está na faculdade. 
     */
    public void setAno(int ano){
        this.ano = ano;
    }
    
}
