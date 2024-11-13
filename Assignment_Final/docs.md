# Visão computacional
## Propósito e Problema a Resolver:
Desenvolver uma plataforma de banco de dados centralizada e segura para armazenar e gerenciar informações de médicos.<br> O sistema permitirá que instituições de saúde, clínicas e hospitais registrem dados essenciais de seus profissionais, como CPF, nome, registro de admissão, endereço, telefone e e-mail de maneira simples, confiável e em conformidade com as regulamentações de privacidade.

## Público-Alvo:
- Hospitais e Clínicas: Departamentos de RH e administrativos que precisam gerenciar as informações dos médicos de forma centralizada.
- Organizações de Saúde: Instituições que buscam uma solução padronizada para armazenar e consultar dados de profissionais de saúde.

## Valor Agregado:
Esse banco de dados oferece:

- Segurança e Conformidade: Proteção dos dados conforme exigências de privacidade e regulamentação.
- Escalabilidade: Sistema preparado para crescer com a necessidade da instituição.

# Requisitos Funcionais

| ID   | Prioridade | Descrição                     | Detalhamento                                                                                      | Estimativa |
|------|------------|-------------------------------|---------------------------------------------------------------------------------------------------|------------|
| RF01 | Alta       | Cadastro de Médicos           | Permitir o cadastro de médicos com CPF, nome, data de admissão, endereço, telefone e e-mail.      | 3 semanas  |
| RF02 | Alta       | Consulta de Médicos           | Permitir busca por médicos utilizando filtros como nome, CPF e data de admissão.                  | 2 semanas  |
| RF03 | Média      | Atualização de Dados          | Permitir que os dados de médicos cadastrados sejam atualizados, como endereço, telefone e e-mail. | 2 semanas  |
| RF04 | Média      | Remoção de Registros          | Permitir exclusão de registros de médicos.                                                        | 1 semana   |
| RF05 | Alta       | Relatórios                    | Gerar relatórios com informações básicas dos médicos cadastrados e exportação em formato TXT.     | 2 semanas  |

# Requisitos Não Funcionais
| ID   | Prioridade | Descrição                     | Detalhamento                                                                                                                                                             | Estimativa |
|------|------------|-------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|
| RNF02| Alta       | Escalabilidade                | Projetar o sistema para suportar aumento de registros e atender a instituições de grande porte.                                                                         | 2 semanas  |
| RNF04| Média      | Desempenho                    | Garantir que consultas a registros sejam realizadas em menos de 2 segundos, mesmo com alto volume de dados.                                                              | 2 semanas  |
| RNF07| Baixa      | Manutenibilidade              | Código modular e documentado, permitindo fácil atualização e manutenção técnica.                                                                                         | 3 semanas  |
