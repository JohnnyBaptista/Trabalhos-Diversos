package Classes.usuarios;
import java.io.Serializable;
/**
 * Classe abstrata dos usuários da biblioteca.
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique.
 */
public abstract class Usuario implements Serializable{
    /**
     * Código de referência do usuário.
     */
    protected String codUsuario;
    /**
     * Nome do usuário.
     */
    protected String nome;
    /**
     * Quantos dias o usuário pode ficar com um livro emprestado.
     */
    protected int diasEmprestimo;
    /**
     * Váriavel utilizada pela interface Serializable.
     */
    private static final long serialVersionUID =  5800515502356035097L;
    /**
     * Construtor abstrato do usuário.
     * @param codUsuario Código de referência do usuário.
     * @param nome Nome do usuário.
     * @param diasEmprestimo Quantos dias o usuário pode ficar com um livro emprestado.
     */
    public Usuario(String codUsuario, String nome, int diasEmprestimo){
        this.codUsuario = codUsuario;
        this.nome = nome;
        this.diasEmprestimo = diasEmprestimo;
    }
    /**
     * @return Código de referência do usuário.
     */
    public String getCodUsuario(){
        return codUsuario;
    }
    /**
     * @param codUsuario Novo Código de referência do usuário.
     */
    public void setCodUsuario(String codUsuario){
        this.codUsuario = codUsuario;
    }
    /**
     * @return Nome do usuário.
     */
    public String getNome(){
        return nome;
    }
    /**
     * @param nome Novo nome do usuário. 
     */
    public void setNome(String nome){
        this.nome = nome;
    }
    /**
     * @return Quantidade de dias que o usuário pode ficar com um livro emprestado.
     */
    public int getDiasEmprestimo(){
        return diasEmprestimo;
    }
    /**
     * @param diasEmprestimo Nova quantidade de dias que o usuário pode ficar com um livro emprestado.
     */
    public void setDiasEmprestimo(int diasEmprestimo){
        this.diasEmprestimo = diasEmprestimo;
    }
}
