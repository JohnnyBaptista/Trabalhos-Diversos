package Classes.usuarios;
/**
 * Subclasse de usuário.
 * @author Eymar Lima, Matheus Prachedes, Carlos Henrique.
 */
public class Professor extends Usuario{
    /**
     * Título acadêmico do professor.
     */
    protected String titulacao;    
    /**
     * Constrói um professor com os dados especificados.
     * @param codUsuario Código de referência do usuário.
     * @param nome Nome do usuário.
     * @param diasEmprestimo Quantos dias o usuário pode ficar com um livro emprestado.
     * @param titulacao Título acadêmico do professor.
     */
    public Professor(String codUsuario, String nome, int diasEmprestimo,String titulacao) {
        super(codUsuario, nome, diasEmprestimo);
        this.titulacao = titulacao;
    }
    /**
     * @return Título acadêmico do professor.
     */
    public String getTitulacao(){
        return this.titulacao;
    }
    /**
     * @param titulacao Nova titulação acadêica do professor.
     */
    public void setTitulacao(String titulacao){
        this.titulacao = titulacao;
    }
}
