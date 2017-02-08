**Don't tweet about this please!**

Install the project workflow utility named `esy`:

```
npm install -g jordwalke/esy.git#beta-v0.0.2
```

Then use `esy` to build and run this `rehydrate` example:

```
git clone https://github.com/chenglou/rehydrate-example.git
esy install
esy bsb -make-world -w
# in another tab
./node_modules/.bin/webpack && open ./src/index.html
```
