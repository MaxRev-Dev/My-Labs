CREATE TABLE [dbo].[prozhyvannya_uchasnykiv]
( 
	[id_prozhyvannya_uchasnykiv] INT NOT NULL PRIMARY KEY IDENTITY, 
    [id_ucasnyky] NCHAR(11) NULL, 
    [id_mistsya_prozhyvannya] NCHAR(11) NULL, 
    [dodatkovo] VARCHAR(255) NULL
)
