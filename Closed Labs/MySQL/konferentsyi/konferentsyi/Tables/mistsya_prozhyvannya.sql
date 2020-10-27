CREATE TABLE [dbo].[mistsya_prozhyvannya]
(
	[id_mistsya_prozhyvannya] INT NOT NULL PRIMARY KEY IDENTITY, 
    [typ_prozhyvannya] VARCHAR(20) NULL, 
    [nazva_prozhyvannya] VARCHAR(200) NULL, 
    [adresa_prozhyvannya] VARCHAR(MAX) NULL, 
    [telefon_prozhyvannya] VARCHAR(100) NULL
)
