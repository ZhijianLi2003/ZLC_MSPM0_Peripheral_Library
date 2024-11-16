exports = {
	displayName: "Default Clock Value",
	moduleStatic: {
		config: [{
			name: "valueType",
			default: "arrayRange",
			options: [{ name: "singleValue" }, { name: "arraySame" }, { name: "arrayRange" }]
		}]
	},
	getDefaultValue: (name) => {
		const valueType = system.modules["/clockTree/defaultValue.js"]?.$static.valueType ?? "arrayRange";
		switch (valueType) {
			case "singleValue":
				return _.size(name);
			case "arraySame":
				return [_.size(name), _.size(name)];
			case "arrayRange":
				return [_.size(name), _.size(name) + 1];
		}
	}
}
