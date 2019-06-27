CREATE TABLE [dbo].[sektsyi]
(
	[id_sektsiyi] INT NOT NULL PRIMARY KEY IDENTITY, 
    [id_konferentsiyi] NCHAR(11) NULL, 
    [nazva_sektsiyi] VARCHAR(MAX) NULL
)
