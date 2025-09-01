# ToolDescription
## Default
### ID=RTEHunter
### Description
  The RTEHunter module of SourceMeter can detect potential runtime errors in Java applications. These runtime errors are represented by the instances of Java class RuntimeException. The detection is based on an interprocedural symbolic execution engine.

# Includes
- general_metadata.md

# Metrics
## RH_CCE
### Default
#### Enabled=true
#### Warning=true
#### DisplayName=ClassCastException
#### WarningText
  %

#### HelpText
  Invalid casting which causes a ClassCastException.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=false
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags


## RH_DBZ
### Default
#### Enabled=true
#### Warning=true
#### DisplayName=Division By Zero
#### WarningText
  %

#### HelpText
  Division by zero causes an ArithmeticException.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=true
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags


## RH_IL
### Default
#### Enabled=false
#### Warning=true
#### DisplayName=Infinite Loop
#### WarningText
  %

#### HelpText
  Infinite loop.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=false
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags


## RH_IOB
### Default
#### Enabled=true
#### Warning=true
#### DisplayName=Index Out Of Bounds
#### WarningText
  %

#### HelpText
  Indexing an array by an index which is less than zero, or greater than its size.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=true
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags


## RH_NAS
### Default
#### Enabled=true
#### Warning=true
#### DisplayName=Negative Array Size
#### WarningText
  %

#### HelpText
  Creating an array with negative size.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=true
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags


## RH_NPE
### Default
#### Enabled=true
#### Warning=true
#### DisplayName=NullPointerException
#### WarningText
  %

#### HelpText
  Null pointer dereferenced which causes a NullPointerException.


#### Tags
- /tool/SourceMeter/RTEHunter
- /general/Runtime Rules

#### Settings
- Priority=Blocker

### java -> Default
#### Enabled=true
#### Calculated
- Annotation
- Class
- Component
- Enum
- Interface
- Method
- Package

#### Tags
