CREATE TABLE [dbo].[spivrobitnyky]
(
	[id_spivrobitnyky] INT NOT NULL PRIMARY KEY IDENTITY, 
    [id_kafedry] INT NULL, 
    [prizvishche] NCHAR(100) NULL, 
    [imya] NCHAR(100) NULL, 
    [pobatkovi] NCHAR(100) NULL
)
