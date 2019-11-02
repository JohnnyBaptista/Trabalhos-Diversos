package Classes;

import java.io.Serializable;

/**
 * Classe Livro, utilizada pelas classes Empréstimo, Item e Usuário
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique.
 */
public class Livro implements Serializable{
    /**
     * Código de referência do livro.
     */
    private String codLivro;
    /**
     * Nome do livro.
     */
    private String nome;
    /**
     * Ano em que o livro foi publicado.
     */
    private int ano;
    /**
     * Boolean reponsável por dizer se o livro está ou não emprestado.
     */
    private boolean emprestado;
    /**
     * Váriavel utilizada pela interface Serializable.
     */
    private static final long serialVersionUID = 1L;
    /**
     * @return Estado atual do livro, true para emprestado e false para disponível.
     */
    public boolean isEmprestado() {
        return emprestado;
    }
    /**
     * Construtor do livro.
     * @param codLivro Código de referência do livro.
     * @param nome Nome do livro.
     * @param ano Ano em que o livro foi publicado.
     */
    public Livro(String codLivro,String nome,int ano){
        this.codLivro = codLivro;
        this.nome = nome;
        this.ano = ano;
        this.emprestado = false;
    }
    /**
     * @param emprestado Novo estado de empréstimo do livro. 
     */
    public void setEmprestado(boolean emprestado){
        this.emprestado = emprestado;
    }
    /**
     * Torna o livro emprestado.
     */
    public void emprestar(){
        this.emprestado = true;
    }
    /**
     * Torna o livro devolvido.
     */
    public void devolver(){
        this.emprestado = false;
    }
    /**
     * @return Código de referência do livro.
     */
    public String getCodLivro(){
        return codLivro;
    }
    /**
     * @param codLivro Novo código de referência do livro.
     */
    public void setCodLivro(String codLivro){
        this.codLivro = codLivro;
    }
    /**
     * @return Nome do livro.
     */
    public String getNome(){
        return nome;
    }
    /**
     * @param nome Novo nome do livro.
     */
    public void setNome(String nome){
        this.nome = nome;
    }
    /**
     * @return Ano de publicação do livro; 
     */
    public int getAno(){
        return ano;
    }
    /**
     * @param ano Novo ano de publicação do livro;
     */
    public void setAno(int ano){
        this.ano = ano;
    }  
}
