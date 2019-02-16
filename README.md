# MINFILE

It is a cli application to generate min file size easily. For example file.css to file.min.css.

[![Build Status](https://travis-ci.com/GauravWalia19/minfile.svg?branch=master)](https://travis-ci.com/GauravWalia19/minfile)

## DEPENDENCIES

* gcc compiler
* bash shell

## PREQUESTIES

* Must have little CLI usage experience (Beginner level)
* Running bash scripts
* Compiling and running c programs

## BUILD

### LINUX

For building in your linux distro use

```bash
bash build.bash
```

Select Y for release/using new update.Now you have fresh binary in bin folder for your distro.

### WINDOWS

Coming soon

## TEST OUR APPLICATION OUTPUT

Feel cool because you can test our application also. For that follow below steps

* Open terminal or cmd in repo root folder
* Go to test directory and see test output using commands:

```bash
cd test
bash test.bash
```

* Enter the filename to convert. Now you can see converted min file in mfiles in test directory.

## USAGE

**Please copy this binary on same location as that of your file which you want to convert.For right use copy your file to bin folder.**

Navigate to bin directory

### Using c binary (For linux distro only)

```bash
./minfile filename.css
```

### Using bash script (For linux distro only)

```bash
bash minfile.bash
```

**You will see new file of name `filename.min.css` present in mfiles folder. Open that file and see the output.**

## FILETYPE SUPPORT

* css
* html (partially supported)
* js (partially supported)
* c (partially supported)

## RESULTS

### CSS

It will convert `test.css to test.min.css`

```css
p {
    background: brown;
}
```

You will get resultant file as test.min.css

```css
p{background:brown;}
```