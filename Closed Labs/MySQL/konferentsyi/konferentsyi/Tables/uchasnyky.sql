CREATE TABLE [dbo].[uchasnyky]
(
	[id_uchasnyky] INT NOT NULL PRIMARY KEY IDENTITY, 
    [id_sektsiyi] NCHAR(11) NULL, 
    [pib] VARCHAR(MAX) NULL, 
    [e_mail] VARCHAR(100) NULL, 
    [telefon] VARCHAR(50) NULL, 
    [stupin] VARCHAR(6) NULL, 
    [zvannia] VARCHAR(8) NULL, 
    [tema] NVARCHAR(MAX) NULL, 
    [prozhyvannia] TINYINT NULL
)
